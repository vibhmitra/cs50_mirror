-- Keep a log of any SQL queries you execute as you solve the mystery.

-- crime took place on July 28
-- at Humphrey street

-- goal: theif, escaped to where, who helped him
-- findings:
--

-- Findings:
--     - Crime time: 2024-07-28 at 10:15 AM
--     - Security Footage Parkin Lot Car that left in that time frame
--     - Eugene saw theif before at ATM on Leggett Street
--     - Theif has CALLED a friend and he is planning to leave on 2024-07-29 (probably check call logs) call took place less than a min
--     - Theif's friend is buying airplane ticket for tommorow.

--     - Bruce, Taylor, Luca,


-- find crime scene descriptions
select * from crime_scene_reports where street = 'Humphrey Street' and month = 7 and day = 28;

-- o/c
-- id : 295, date: 2024-07-28
-- description: Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
--              Interviews were conducted today with three witnesses who were present at the
--              time – each of their interview transcripts mentions the bakery.


-- interviews of three people that  mentions 'bakery'
select id, name, transcript from interviews where year = 2024 and month = 7 and day = 28 and transcript like '%bakery%';
-- o/c :
-- Ruth Statement:  Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
--                  If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot
--                  in that time frame.
-- Eugene Stmt   :  I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's
--                  bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- Raymond Stmt  :  As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call,
--                  I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
--                  The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- BANKING INFO NAME
-- Atm Trasactions that took plac:
select * from atm_transactions where month = 7 and day = 28 and transaction_type = 'withdraw' and atm_location = 'Leggett Street';
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 246 | 28500762       | 2024 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 264 | 28296815       | 2024 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 266 | 76054385       | 2024 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 267 | 49610011       | 2024 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 269 | 16153065       | 2024 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 288 | 25506511       | 2024 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 313 | 81061156       | 2024 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- | 336 | 26013199       | 2024 | 7     | 28  | Leggett Street | withdraw         | 35     |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+

select people.name, bank_accounts.account_number from people
join bank_accounts on bank_accounts.person_id = people.id
where bank_accounts.account_number in (
    select account_number from atm_transactions where month = 7 and day = 28 and transaction_type = 'withdraw' and atm_location = 'Leggett Street'
);

-- Account number with names
-- +---------+----------------+
-- |  name   | account_number |
-- +---------+----------------+
-- | Bruce   | 49610011       |
-- | Diana   | 26013199       |
-- | Brooke  | 16153065       |
-- | Kenny   | 28296815       |
-- | Iman    | 25506511       |
-- | Luca    | 28500762       |
-- | Taylor  | 76054385       |
-- | Benista | 81061156       |
-- +---------+----------------+


-- LICENSE PLATE MYSTERY SOLVED
-- cars that exit after the time of theft:
select * from bakery_security_logs where month = 7 and day = 28 and hour = 10 and minute < 25 and activity = 'exit';
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | id  | year | month | day | hour | minute | activity | license_plate |
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | 260 | 2024 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
-- | 261 | 2024 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
-- | 262 | 2024 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
-- | 263 | 2024 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
-- | 264 | 2024 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
-- | 265 | 2024 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
-- | 266 | 2024 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
-- | 267 | 2024 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
-- +-----+------+-------+-----+------+--------+----------+---------------+

-- License Plate with there Owner name
select people.name, people.license_plate from people where license_plate in (select license_plate from bakery_security_logs where month = 7 and day
 = 28 and hour = 10 and minute < 25 and activity = 'exit');
-- +---------+---------------+
-- |  name   | license_plate |
-- +---------+---------------+
-- | Vanessa | 5P2BI95       |
-- | Barry   | 6P58WS2       |
-- | Iman    | L93JTIZ       |
-- | Sofia   | G412CB7       |
-- | Luca    | 4328GD8       |
-- | Diana   | 322W7JE       |
-- | Kelsey  | 0NTHK55       |
-- | Bruce   | 94KL13X       |
-- +---------+---------------+

--- Outcome
-- Based on Withdraw at atm and license plate
-- suspects are: Bruce, Luca, Diana, Iman



-- Call that took place and less that 60s
-- sqlite> select * from phone_calls where day = 28 and month = 7 and duration < 60;
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 221 | (130) 555-0289 | (996) 555-8899 | 2024 | 7     | 28  | 51       |
-- | 224 | (499) 555-9472 | (892) 555-8872 | 2024 | 7     | 28  | 36       |
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2024 | 7     | 28  | 45       |
-- | 251 | (499) 555-9472 | (717) 555-1342 | 2024 | 7     | 28  | 50       |
-- | 254 | (286) 555-6063 | (676) 555-6554 | 2024 | 7     | 28  | 43       |
-- | 255 | (770) 555-1861 | (725) 555-3243 | 2024 | 7     | 28  | 49       |
-- | 261 | (031) 555-6622 | (910) 555-3251 | 2024 | 7     | 28  | 38       |
-- | 279 | (826) 555-1652 | (066) 555-9701 | 2024 | 7     | 28  | 55       |
-- | 281 | (338) 555-6650 | (704) 555-2131 | 2024 | 7     | 28  | 54       |
-- +-----+----------------+----------------+------+-------+-----+----------+


-- Passenges that are flying on 29 with name
select people.name, people.passport_number from people
join passengers on people.passport_number = passengers.passport_number
where passengers.flight_id in (
    select id from flights where day = 29 and month = 7
);

-- +-----------+-----------------+
-- |   name    | passport_number |
-- +-----------+-----------------+
-- | Gloria    | 2835165196      |
-- | Kristina  | 6131360461      |
-- | Douglas   | 3231999695      |
-- | Diana     | 3592750733      |
-- | Christian | 2626335085      |
-- | Michael   | 6117294637      |
-- | Ethan     | 2996517496      |
-- | Charles   | 3915621712      |
-- | Dennis    | 4149859587      |
-- | Jose      | 9183348466      |
-- | Jennifer  | 7378796210      |
-- | Brandon   | 7874488539      |
-- | Matthew   | 4195341387      |
-- | Emily     | 6263461050      |
-- | Douglas   | 3231999695      |
-- | Jordan    | 7951366683      |
-- | Doris     | 7214083635      |
-- | Sofia     | 1695452385      |
-- | Bruce     | 5773159633      |
-- | Edward    | 1540955065      |
-- | Kelsey    | 8294398571      |
-- | Taylor    | 1988161715      |
-- | Kenny     | 9878712108      |
-- | Luca      | 8496433585      |
-- | Daniel    | 7597790505      |
-- | Carol     | 6128131458      |
-- | Rebecca   | 6264773605      |
-- | Sophia    | 3642612721      |
-- | Heather   | 4356447308      |
-- | Marilyn   | 7441135547      |
-- | Richard   | 7894166154      |
-- | Thomas    | 6034823042      |
-- | Brooke    | 4408372428      |
-- | Larry     | 2312901747      |
-- | Steven    | 1151340634      |
-- | John      | 8174538026      |
-- | Pamela    | 1050247273      |
-- | Melissa   | 7834357192      |
-- +-----------+-----------------+

-- new sus lits: Luca, Bruce, Taylor, Diana


-- caller map with people
select people.name, people.phone_number from people
where people.phone_number in (
    select caller from phone_calls where day = 28 and month = 7 and duration < 60
)

-- +---------+----------------+
-- |  name   |  phone_number  |
-- +---------+----------------+
-- | Kenny   | (826) 555-1652 |
-- | Sofia   | (130) 555-0289 |
-- | Benista | (338) 555-6650 |
-- | Taylor  | (286) 555-6063 |
-- | Diana   | (770) 555-1861 |
-- | Kelsey  | (499) 555-9472 |
-- | Bruce   | (367) 555-5533 |
-- | Carina  | (031) 555-6622 |
-- +---------+----------------+

-- new sus: Bruce, Taylor, Diana

-- earliest flight clue
select * from passengers where flight_id = 36;
-- +-----------+-----------------+------+
-- | flight_id | passport_number | seat |
-- +-----------+-----------------+------+
-- | 36        | 7214083635      | 2A   |
-- | 36        | 1695452385      | 3B   |
-- | 36        | 5773159633      | 4A   |
-- | 36        | 1540955065      | 5C   |
-- | 36        | 8294398571      | 6C   |
-- | 36        | 1988161715      | 6D   |
-- | 36        | 9878712108      | 7A   |
-- | 36        | 8496433585      | 7B   |
-- +-----------+-----------------+------+

-- name who took early flights on 29
select name, passport_number from people where people.passport_number in
(select passport_number from passengers where flight_id = 36);
-- +--------+-----------------+
-- |  name  | passport_number |
-- +--------+-----------------+
-- | Kenny  | 9878712108      |
-- | Sofia  | 1695452385      |
-- | Taylor | 1988161715      |
-- | Luca   | 8496433585      |
-- | Kelsey | 8294398571      |
-- | Edward | 1540955065      |
-- | Bruce  | 5773159633      |  << common
-- | Doris  | 7214083635      |
-- +--------+-----------------+

-- Culprit: Bruce

-- check who he calls on 28 with duration less that 60s
select people.name, phone_calls.receiver from people
join phone_calls on people.phone_number = phone_calls.caller
where people.name = 'Bruce' and phone_calls.duration < 60 and phone_calls.day = 28;

-- name of the
select people.name from people where people.phone_number =
(select phone_calls.receiver from people
join phone_calls on people.phone_number = phone_calls.caller
where people.name = 'Bruce' and phone_calls.duration < 60 and phone_calls.day = 28);
-- +-------+
-- | name  |
-- +-------+
-- | Robin |
-- +-------+

-- find flight id of bruce
select flight_id from passengers
where passengers.passport_number = (
        select passport_number from people
        where people.name = 'Bruce'
);

-- flight that was smallest
select * from flights where day = 29 and month = 7 and id = 36;
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 36 | 8                 | 4                      | 2024 | 7     | 29  | 8    | 20     |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+

-- destination flight
select city from airports where id = 4;
-- +---------------+
-- |     city      |
-- +---------------+
-- | New York City |
-- +---------------+

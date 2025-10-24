# Week8 - HTML, CSS, JavaScript
The markup language


## How internet works?

- **internet** - inter-connected network of networks.
- **routers** - routing info from one location to another, basically path-decider
    - routers speaks TCP/IP (two protocol).
    - protocol is just set of convention kinda like how we human shake hands.
- **IP (internet protocol)**
    - every computer on network has IP. (0 - 255) IPv4
    - new is ipv6
- computers generally borke the data into smaller packets.
- **TCP** (transmission control protocol)
    - helps computers to id the fragments of packets
- ports: unique numeric identifier for specific service
    - like 80 for http, 443 for https, 22 for ssh etc.
    - so now ip will look like - 1.2.3.4:80 that means its going to be a web-server
    - source port and destination port
- both TCP and IP together allows us to uniquely address computers on internet and gauranteed delivery of data.
- **DNS (Domain name servers)**
    - translates domain name into ip address so we don't have to remember those weird numbers in ip.
    - it contains domain_name along with its corresponding ip.
    - if first dns server didn't find one in its list, then it will asks second dns server to get the ip.
    - your computer also has a local dns server that caches all of the ip's after its first connection.
    - also has expiration date
- **DHCP**
    - dynamic host config protocol
    - its purpose is to give ip to your device when it boots up.
    - device basically asks network - whats my ip address? and the network then assign it a random ip address based on availibility.
    - also tells what dns server to user.
    - also tells what gateway (basically router) to use.
- **HTTP (hyper-text transfer protocol)**
    - prefixed automatically in browsers http://<domain_name>/
    - https://www.example.com/folder\
        - https:// - this is just protocol
        - host name: wwww
        - domain name: example.com
        - TLD: (top level domains) - .com, .gov, .jp, .tv
    - in this protocol: there can requests like:
        - GET - get me smth
        - POST - send smth
        - eg:
            ```
            GET / HTTP/2
            host: www.example.com/
            ```
    - then the response will be like:
        ```
        HTTP/2 200
        Content-Type: text/html
        ```
    - u can use tools like curl (connect url)
    - http status codes: 200 OK, 301 Moved Permanently, 404 Not Found, 403 Forbidden

## HTML (hypertext markup language)
- a language to write webpages, NOT a programming language tho
- has
    - tags
    - attributes
- A standard HTML document begins with `<!DOCTYPE html>` that sort of tell the browser that this file is a webpage.
- extension is - `.html`, `.htm`
- https means there is server that is listening at 443 port
- its possible that multiple services are running on that domain so we can use different ports for different services
- `html-server` command allows server
- basic structure of html
    ```html
    <!DOCTYPE html>
    <html lang="en">
        <head>
            <title>
                hello, duck!
            </title>
        </head>
        <body>
            hello, body
        </body>
    </html>
    ```
- the structure of that markup is called DOM (Document object model)
- html only allow single space between paragraphs until you told it to do so.
- static html is only composed of like html

- dynamic website can responce dynamically.
    - example of dynamic url: https://www.example.com/**path?key=value&key=value**

- form validation using regular expressions (regex)

## CSS (cascading style sheet)
- just to style the web page elements
- properties : colors + structure + font sizing + positioning
- ways to apply props:
    - type selectors
    - class selectors
    - ID selectors
    - attribute selector
- we can add it in head of html file.
    - inside `<style> { all styles here } </style>` tag
    - using link tag.
- borwser adds its own default stylesheet aka useragent styles.

- **Frameworks:** a prewritten lib / code.
    - css framework: bootstrap css, tailwind css etc.
        - helps you make websites faster.

## JavaScript
- adds functionality to web pages.
- makes it dynamic.
- javascript elements:
    - conditionals
        ```js
        if (x > y)
        {

        }
        else if (x < y)
        {

        }
        else
        {

        }

        ```
    - var decleration
        ```js
        let foo = 8; // semicolon is not necessary tho
        ```
- adding to html using `<script>` tag - canbe inline of at head.
- javascript is event-driven.
    - so many events happen in browser so in this language.
    - JS listen to this events.
- JS will be executed at client side.

- `let name = document.querySelector('#name').value;` : here documnet is like DOM

## Shorts Notes
- **IP address**
- Allocating 32-bit address to each device hoping to connect to the internet.
    - Instead of hexadecimal, we represent it as four cluster of 8-bits using decimal notation.
    - IPv4:  w.x.y.z ,
        - each w,x,y,z is non-negative
        - range [0,255]
    - roughly 4 billion addresses to give out.
    - population of wrold is > 7 billion so we are out of ips (theoretically).
    - to over come this IPV6 came
    - IPv6 Address: s:t:u:v:w:x:y:z
        - each s, t, u, v, w, x, y and z is represented by 1-4 hexadecimal digits in the range [0, ffff].

- **DHCP (dynamic host control protocol)** assigns IP to devices.
    - before DHCP a system admin assigns it manually (physically)

- **DNS (domain name system)**
    - DNS helps us translate IP addr to memorable names like instead 123.653.564.345:80 info.host1.net
    - There is no DNS record that will contains all of the internet.
    - large DNS server system are more like aggregators, collecting smaller sets of DNS info and pool them togenther, updates it frequently using reccussion
- **Access Points**
    - is like router (modem, switches, etc)
    - using which same ip is assingned to multiple people
    - ip address is assigned to a router, whose job is to act as a traffic manager that allows data requests from all the devices that's connected to it.
    - router also assigns private IP to each device, your device first sends request to router and then the router will connect you to internet.
    - that's why we say internet is decentralised.

- **Internet** is like interconnected network comprised of smaller netwrok woven together and communicate using various protocals.
- not every netwrok can connected to each and every other network.
- we do need each network to be able to talk to each other.
- here come the router again
    - per network can connect to router, and router will contains like *routing table*
    - recurrsion will help here.
    - IP- n.x.x.x where n is its network number.
    - and thats scalable as each network is not directly connected
- All data first gets broken into small packets by IP, then it get sent.
    - so if you loose one of the packet you just have to send that lost packet only.
    - every packet can take multiple path to reach it's destination.

- **TCP (transmission control protocol)**
    - directs packets to **correct service** or port, on the receiving machine.
    - maintains garanteed delivery
    - Includes info about the ordering of packets, ports.
    - Common Ports / Service
        - FTP (file transfer protocol): 21
        - SSH (secure shell): 22
        - SMTP (simple mail transfer protocol): 25
        - DNS: 53
        - HTTP (web browsing), HTTPS (secure web): 80, 443
    - Typical TCP Packet: `[(Receiver IP), (25 / 1 of 4), (<DATA>)]`

- **HTTP (hyper text transfer protocol)**
    - Application layer protocol
    - specify the formats how clients requests pages from server

- **HTML**
    - hyper text markup language
    - not a programming language cuz it doesn't have vars, logic, func, etc.
    - uses startign and closing tags like this `<>   </>`
    - `<html>` tags is where everything is wrapped in
    - `<head>` contains title tags, meta tags, styles, external sources.
    - only one whitespace is considered in html paragraph tags until defined
    - common tags for tweaking the text: `<b></b>` for bold, `<i></i>` for italics, `<u></u>` for underline.
    - `<p> i am a paragraph! </p>`, `<h1> I am a header! </h1>`
    - header tags are using h1 to h6, h1 being bigger, h6 being smaller.
    - lists: `<ul></ul>` for unordered list, `<ol></ol>` for ordered list, `<li>` for list items nested in b/w those tags.
    - `<table> </table>` for tables
        - `<tr>` - for table row
        - `<td> </td>` - table data
        - `<thead> </thead>` - for table heading
    - `<form> </form>`
    - `<div> </div>` - a space
    - `<input name=X type=Y/>` - define a field within an HTML form. X is a unique identifier for that field, Y is what type of field that is. AND THis is also a  *self closing tag*.
    - `<a href="www.xyz.com">, </a>` - anchor tag with attribute hypelink reference.
    - `<img scr=X ... />` - image tag
    - `<!DOCTYPE html>` - SPecific to html5, this is the tag that lets the browser know that's the standard you are using.
    - `comment tag: <!-- xxddxx -->`
    - html will not fail with syntax error, we can use validator tho.

- **CSS (cascading style sheets)**
    - just to style html webpage.
    - normal tags selector:
        ```css
        body {
            color: red;
            font: serif;
            border: style color width;
        }
        ```
    - ID selector
        ```css
        #unique
        {
            border: 3px dotted blue;
            color: red;
        }
        ```
    - Class selector
        ```
        .students
        {
            background-color: yellow;
            opacity: 0.7;
        }
        ```
    - style sheets can be written directly into html's `<style>` tag or can be linked at head using `<link >` tag
    - it also can be added to inline css, emmbedded directly into the tags.

- **JavaScript**
    - Mordern programming language
    - orginated in 1995
    - Javascript, HTML, CSS makes up the web experience.
    - is client side when visiting a website
    - how to have it in html?
        - in `<script>` tag indise head or on body
        - or just link src them in head.
    - local variable init: var x = 5
    - all conditionals like C lang.
    - same for loop.
    - functions are introduced using `fucntion` and can be **annonymous**.
    - Arrays: var num =  [1, 4, 5, 7, true, 3.33, 'five']
    - Objects: can be use as oops ex: `object.function();`
    - Loops (redux):
        ```js
        var someArray = ['one', 'two', 'three', 'four']

        for (var key in someArray)
        {
            // will print keys but as the array doesn't have any keys
            // it will show only 0, 1, 2, 3
        }

        for (var key of someArray)
        {
            // will print values
            // one, two, three, four
        }

        ```
    - `console.log("xxxx")` - use to log errors
    - Functions (redux)
        - array are a special case of an object.
        - a method for arrays called map.
        - F
            ```js
            var nums = [1, 2, 3, 4, 5];

            // doubling up the numbers elements
            nums = nums.maps(function(num) {
                return num * 2;
            });
            ```
    - **Events**: an evens is html and js is a response to user interaction.
    - example - `<button onclick="alertName(event) > Button 1</button>"`
        ```

        <button onclick="alertName(event)" > Button 1</button>
        <button onclick="alertName(event)" > Button 2</button>
        ...
        ...

        function alertName(event)
        {
            var trigger = event.srcElement;
            alert('You clicked on ' + trigger.innerHTML);
        }
        ```
- **DOM (Document object model): **
    - everything is like object in html thats why we say it follows object model
    - it has properties and methods that can be used to change the dom manupulation.
    - Some DOM properties
        - innerHTML: holds html inside a set of html tags
        - nodeName: name of an html elements of its attribute
        - id : the id
        - parentNode: a ref to node one lvl up in the dom
        - childNode: a ref to node one lvl down in the dom
        - attributes: array of attributes of html element
        - style: an object encapsulating the css/html styling of an element
    - some DOM methods:
        - getElementById(id): element the specific id below this point in dom
        - getElementsByTagName(tag) : array of all elemetns that given below this point in dom
        - appendChild(node): add given node in dom below this point
        - removeChild(node): remove the specified child node from dom.
    - **jQuerry**-
        - is a js library to shorten the client-side scripting like dom manupulation.
        - diff
            ```jquery
            document.getElementById('colorDiv').style.backgroundColor = 'green'
                is same in jQuery
            $('#colorDiv').css('background-color', 'green');
            ```
## Section

- 


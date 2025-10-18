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
    - example of dynamic url: https://www.example.com/ **path?key=value&key=value**

- form validation using regular expressions (regex)

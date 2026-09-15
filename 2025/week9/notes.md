# Week9 - Flask

- http-server is serve to port 80 and listens to http requests
- JavaScript only stores stuffs at client-side NOT server side
- when we add that trailing / in url it means give me the default one
- https://www.example.com/path - the path
- https://www.example.com/route - the path that is not really exists this is why route.
- https://www.example.com/route?key=value&key=value
- Now we will work with Backend part of the web

```txt
GET /search?q=cats HTTP/2
Host: www.google.com
```

## Flask
- its a micro-framework for web programming in python
- `flask run` <- to run
- able to generate webpage dynamically.
- we need like two files:
    - app.py
    - requirements.txt - contains dependencies
- a simple web example
    ```python
    from flask import Flask

    app = Flask(__name__)   # pls turn this file into a web app & let me refer it by a variable 'app'

    @app.route("/")     # @ sign is decorator: wrapping function inside another, or making route where / is route
    def index():
        return "hello, world!"  # returns simple string
    ```

- Jinja is a templating engine that flask people use
- GET method puts / sents the input using urls
    - GET parameter are save in dictionary `request.args.get`
- POST method hides it, privately
    - POST parameter are saved in `request.form.get`
## MVC
- froshim.db - model
- app.py - controller
- templates/ - view

## Talking to server
```txt
    POST

    HTTP/2 200
    Content-Type: text/html
    Set-Cookie: session=value

    Browser sends another header
    GET / HTTP/2
    Host: accounts.google.com
    Cookie: session=value

```
- Cookie: a big random value stored on your browsers
- Servers give those cookie to your browser
- We can use it to keep logged in our user even if he moves or refreshes pages

- Flask uses session
- if you wanna know who is logged in on per user browser basis, use sessions
- if you use db every user kinda have access to those data


# Shorts - Flask
- web frameworks makes building up server easy by providing helper functions
- populars ones are :
    - Flask - lightweight
    - Django
    - Pyramid
- html are static and therefore it can't behave dynamically.
- also static html is best for content heavy website but if you want interactivity like saving data from user or smthg like that, static html simply can't do that.

## Gettng Started w/ Flask
- Import Flask class - `from flask import Flask`
- `app = Flask(__name__)` : basically `__name__` is just getting the file name which is a flask app.
- now write function:
    ```python
    @app.route("/")  # 👈 these are decorators, defining path/route
    def index():
        return "You are at the index page."
    @app.route("/sample")
    def sample():
        return "You are at the sample page."
    ```
- Decorators are used, in flask, to associate a particular function with a particular URL.
- Decorators also have more general use in Python.

- We can also pass data in URLs, akin to using HTTP GET
    ```python

    @app.route("/show/<number>")
    def show(number):
        return "You passed in {}".format(number)

    ```
- Data also can be passed in via HTTML forms, as w/ POST but we need to indicate that Flask should respond to HTTP POST request explicitly.
    ```python
    @app.route("/login", methods=["GET", "POST"])
    def login():
        if not request.form.get("username") # go and retrieve the form a field called "username"
            return apology("must provide username")
    ```
- We could also vary the behaviour of our function on the type of HTTP request recieved
    - So we could do two different things w/ the same URL
    - like here:
        ```python

        @app.route("/login", methods=["GET", "POST"])
        def login():
            if request.method == "POST": # checking what was the method
                # do one thing
            else:
                # do smth different
        ```
- other functions:
    - url_for()
    - redirect()
    - session() - check if user is logged in, session is global var accessible by all webpages.
    - render_template() - use template to generate html or return html
    - More stuff at: [Flask Docs](https://flask.palletsprojects.com/en/stable/)

## AJAX (old name when XML was relevant: Asynchronous JavaScript and XML)
- everything to this point we have done has been client side.
- We can able to update part of webpage without refreshing the whole page (all this thing server side)
- We use `XMLHttpRequest` to request async, this is special JavaScript object
- typically a anonymous function
- readyState property will change 0, 1, 2, 3, 4 (final) and with 200 OK thg then you will be able to make AJAX requests
    ```js

    function ajax_request(argument)
    {
        var aj = new XMLHttpRequest();
        aj.onreadystatechange == function() {
            if (aj.readyState == 4 && aj.status == 200)
                // do something in page or whtev
        };

        aj.open("GET", /* url */, true);
        aj.send();
    }

    ```

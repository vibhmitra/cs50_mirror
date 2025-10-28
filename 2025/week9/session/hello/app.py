from flask import Flask, render_template, request

app = Flask(__name__)   # pls turn this file into a web app & let me refer it by a variable 'app'


# @ sign is decorator: wrapping function inside another, or making route where / is route
@app.route("/")
def index():
    return "hello, world!"  # returns simple string

# sending html
@app.route("/fullpage")
def fullpage():
    return '<!DOCTYPE html><html lang="en"><head><title>full page demo</title></head><body><h1>hello world! with full page</h1></body></html>'

# render templates | flask know its should be on html
@app.route("/render_template")
def usingtemplate():
    return render_template("index.html")

# user input | request it from browser: 5000.app.github.dev/user_input?name=vi
@app.route("/user_input")
def userinput():
    if "name" in request.args:
        name = request.args["name"]     # gives python key "name" inside of request.args dict. and then save it in 'name' variable
    else:
        name = "world"
    return render_template("userinput.html", username=name)

# to avoid if-else stuff.
@app.route("/user_input2")
def userinput2():
    name = request.args.get("name", "world (using request.args.get())")  # this will try to find the key "name" and if ain't find it  it will return the second argument by default
    return render_template("userinput.html", username=name)

@app.route("/greet")
def greetin():
    name = request.args.get("name", "world")
    return render_template("greetin.html", username=name)

@app.route("/greetout")
def greetout():
    name = request.args.get("name", "world")
    return render_template("greetout.html", username=name)

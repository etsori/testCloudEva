import os

from flask import Flask

app = Flask(__name__)


@app.route("/")
def index():
    return "Привет от Евы!!"


@app.route("/index")
def index1():
    return '1'


if __name__ == '__main__':
    port = int(os.environ.get("PORT", 5001))
    app.run(host='0.0.0.0', port=port)

# This Python file uses the following encoding: utf-8
from os import path
from flask import Flask, jsonify, request
import pdfkit
import os

app = Flask(__name__)

@app.route('/', methods=['POST', 'GET'])
def route():
    return jsonify(data="Salama POST Pdf Server")


@app.route('/convert', methods=['POST'])
def convert():
    print("Starting a conversion")
    json = request.json
    html = json["html"]
    state = _convert(html)

    if state:
        return jsonify(data=True, path=os.path.expanduser("~") +"/Documents/PriceList.pdf")
    else:
        return jsonify(data=False, path="")


def _convert(html):
    try:
        options = {
            'page-size':'A4',
            'encoding': "UTF-8",
            'margin-top': '1.905cm',
            'margin-bottom': '1.905cm',
            'margin-left': '1.905cm',
            'margin-right': '1.905cm',
            'custom-header' : [
                ('Accept-Encoding', 'gzip')
            ],
            'cookie': [
                ('cookie-name1', 'cookie-value1'),
                ('cookie-name2', 'cookie-value2'),
            ]
        }

        file = os.path.expanduser("~/Documents/PriceList.pdf")
        print("Path: ", file)

        if os.path.exists(file):
            os.remove(file)

        pdfkit.from_string(html, file, options=options)
        return True
    
    except Exception as e:
        print('Error at converting: ', e)
        return False


if __name__ == "__main__":
    app.run()

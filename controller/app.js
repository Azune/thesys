(
    function () {
        'use strict';

        let SerialPort = require('serialport'),
            Buffer = {
                data: [],
                length: 0,
                reading: false
            },
            Serial = new SerialPort('COM3', {
                baudRate: 9600,
                autoOpen: false
            });

        console.log('Connecting with firmata...');

        Serial.on('open', () => {
            console.log('Firmata connected to COM3.');
            Serial.flush();
        });

        Serial.on('error', (error) => {
            console.log('An error occurred: ', error.message);
        });

        Serial.on('data', (data) => {
            let bytes = [],
                startOfBuffer = data.indexOf(10),
                endOfBuffer = data.indexOf(13),
                index;

            for (index = 0; index < data.length; index += 1) {
                bytes.push(data[index]);
            }

            /*if (Buffer.reading === false && bytes.contains(10)) {
                Buffer.reading = true;
            } else if (Buffer.reading === true && bytes.contains(13)) {
                Buffer.reading = false;
                console.log(Buffer.data);
            } else if (Buffer.reading) {
                Buffer.push();
            }*/
            console.log(data);
        });

        Serial.open();
    }()
);

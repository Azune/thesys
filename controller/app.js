(
    function () {
        'use strict';

        let SerialPort = require('serialport'),
            Buffer = {
                data: [],
                reading: false
            },
            Serial = new SerialPort('COM3', {
                baudRate: 9600,
                autoOpen: false
            }),
            devices = [];

        console.log('Connecting with firmata...');

        Serial.on('open', () => {
            console.log('Firmata connected to COM3.');
        });

        Serial.on('error', (error) => {
            console.log('An error occurred: ', error.message);
        });

        Serial.on('data', (data) => {
            let hex = data.toString('hex'),
                index = 0;
            
            for (index; index < hex.length; index += 2) {
                let value = hex[index].concat(hex[index + 1]);
                Buffer.data.push(value);
            }
            
            BufferRead();
        });

        function BufferRead() {
            let ls = '0a',
                le = '0d',
                data = Buffer.data,
                line;
            
            data.splice(0, data.indexOf(ls));
            line = data.splice(0, data.indexOf(le));
            
            console.log(line);
        }
        
        Serial.open();
    }()
);

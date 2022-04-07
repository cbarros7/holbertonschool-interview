#!/usr/bin/node

const myArray = process.argv.slice(2);
const request = require('request');

if (Number.isInteger(parseInt(myArray[0]))) {
  request('https://swapi.dev/api/films/' + myArray[0],
    async (error, response, body) => {
      if (error) console.error('error:', error);
      const linksArray = JSON.parse(body).characters;
      for (let index = 0; index < linksArray.length; index++) {
        const name = await getName(linksArray[index]);
        console.log(name);
      }
    });
}

function getName (link) {
  const name = new Promise(
    (resolve, reject) => {
      request(link, (error, response, body) => {
        if (error) console.error('error:', error);
        resolve(JSON.parse(body).name);
      });
    });
  return name;
}

#!/usr/bin/node
const dict = require('./101-data').dict;

const occurences = {};

for (const index in dict) {
  const count = dict[index];
  if (count in occurences) {
    occurences[count].push(index);
  } else {
    occurences[count] = [index];
  }
  console.log(occurences);
}
console.log(occurences);

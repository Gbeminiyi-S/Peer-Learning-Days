#!/usr/bin/node
const size = parseInt(process.argv[2]);
if (isNaN(size) || size < 1) {
  console.log('Missing size');
} else {
  /**
  for (let i = 0; i < size; i++) { // height
    let symbol = '';
    for (let j = 0; j < size; j++) { // width
      symbol += 'X'; // symbol = 'XX'
    }
    console.log(symbol);
  }
  **/
  const symbol = 'X'.repeat(size);
  for (let i = 0; i < size; i++) {
    console.log(symbol);
  }
}

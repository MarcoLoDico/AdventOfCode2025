const fs = require("fs");

function main() {
  let total = 0;

  const lines = fs.readFileSync("input.txt", "utf8")
    .split("\n")
    .map(line => line.trim())
    .filter(line => line.length > 0);

  for (let line of lines) {
    let largestSeen = 0;

    for (let i = 0; i < line.length - 1; ++i){
      for (let j = i + 1; j < line.length; ++j){
        const curr = Number(line[i]) * 10 + Number(line[j]);
        if (curr > largestSeen){
          largestSeen = curr;
        } 
      }
    }

    total += largestSeen;
  }

  console.log(total);
}

main();

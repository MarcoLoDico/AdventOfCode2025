const fs = require("fs");

function main() {
  let total = 0;

  const lines = fs.readFileSync("input.txt", "utf8")
    .split("\n")
    .map(line => line.trim())
    .filter(line => line.length > 0);

  for (let line of lines) {
    let i = 0;   
    // Decreasing order == largest number for this problem
    // So use monotonic stack!
    while (i < line.length){
      if (line.length <= 12) break;

      if (i < line.length - 1 && Number(line[i]) < Number(line[i + 1])){
        // If the two chars represent an increasing order then pop the current char
        line = line.slice(0, i) + line.slice(i + 1);
        if (i > 0){
          // This protects against the 1119 ending case
          --i;
        }
        continue;
      }

      ++i;
    }

    if (line.length > 12){
      line = line.substring(0, 12);
    }
    
    total += Number(line);
  }

  console.log(total);
}

main();

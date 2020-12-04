const fs = require("fs");

const xs = fs.readFileSync("input.txt", "utf8").split("\n\n");
const ys = ["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"];

console.log(xs.filter(x => ys.every(y => x.includes(y))).length)

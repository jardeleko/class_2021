let i = ''
let lines
process.stdin.on('data', c => i += c)
process.stdin.on('end', () => {
  lines = i.split('\n') // your input text, split by lines
  main()
})
 
function main() {
  let t = parseInt(lines.shift())
 
  while (t > 0) {
    const p = parseInt(lines.shift())
 
    if (p === 5) {
      console.log(2, 4)
    } else {
      console.log(2, (p - 1) / 2)
    }
    t--
  }
}
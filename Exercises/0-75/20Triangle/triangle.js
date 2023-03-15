/**
 * @param {number[][]} triangle
 * @return {number}
 */
function buildTree(triangle) {
    let h = triangle.length
    let previousNodes = []
    for (let i = h - 1; i >= 0; i--) {
        let curRow = triangle[i]
        let nextNodes = []
        for (let j = 0; j < curRow.length; j++) {
            let children = []
            if (previousNodes.length > 0) {
                children = [previousNodes[j], previousNodes[j + 1]]
            }
            let addend = 0
            if (children.length) {
                addend = Math.min(...children.map((x)=>x.v))
            }
            let newNode = { v: triangle[i][j] + addend, c: children }
            nextNodes.push(newNode)
        }
        previousNodes = nextNodes
    }
    return previousNodes[0]
}
function dfs(node) {
    // console.log(`node is ${JSON.stringify(node)}`)
    const children = node.c
    // console.log(`children is ${JSON.stringify(children)} va is ${node.v}`)
    const va = node.v
    if (children.length > 0) {
      // console.log(`continuing and children is ${JSON.stringify(children)}`)
      const left = children[0]
      const right = children[1]

      const leftRes = dfs(left) + va
      const rightRes = dfs(right) + va
      // intereseting how this works but 
      // Math.min(va+dfs(children[0]), va+dfs(children[1])) does not work 
      const m = Math.min(leftRes, rightRes)
      return m
    } else {
      return va
    }
}
var minimumTotal = function (triangle) {
    // build tree
    let tree = buildTree(triangle)
    // let min = dfs(tree)
    return tree.v
    
};

triangle = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
Output = 11
console.error(`expect ${Output}, ${minimumTotal(triangle)}`)

triangle = [[-10]]
Output = -10
console.error(`expect ${Output}, ${minimumTotal(triangle)}`)

// res = dfs({"v":4,"c":[]})
// console.log('res is ', res)
res = dfs({"v":6,"c":[{"v":4,"c":[]},{"v":1,"c":[]}]})
console.log('7 is ', res)
// [{ 
//     "v": 2, "c": [{ "v": 3, 
//                     "c": [{
//                          "v": 6, "c": [{
//                              "v": 4, "c": [] }, { 
//                                 "v": 1, "c": [] }] },
//                           { "v": 5, "c": [{ 
//                             "v": 1, "c": [] },
//                              { "v": 8, "c": [] }] }] },
//                  { "v": 4, "c": [{ 
//                     "v": 5, "c": [{ 
//                         "v": 1, "c": [] }, { "v": 8, "c": [] }] },
//                          { "v": 7, "c": [{ 
//                             "v": 8, "c": [] }, { "v": 3, "c": [] }]
//                          }] }] }]
/**
 * @param {number[][]} triangle
 * @return {number}
 */
function buildTree(triangle) {
    h = triangle.length
    previousNodes = []
    for (let i = h - 1; i >= 0; i--) {
        curRow = triangle[i]
        nextNodes = []
        for (let j = 0; j < curRow.length; j++) {
            children = []
            if (previousNodes.length > 0) {
                children = [previousNodes[j], previousNodes[j + 1]]
            }
            newNode = { v: triangle[i][j], c: children }
            nextNodes.push(newNode)
        }
        previousNodes = nextNodes
    }
    console.error(`previousNodes is ${JSON.stringify(previousNodes)}`)
}
var minimumTotal = function (triangle) {
    // build tree
    buildTree(triangle)
};

triangle = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
Output = 11
console.error(`expect ${Output}, ${minimumTotal(triangle)}`)

triangle = [[-10]]
Output = -10
console.error(`expect ${Output}, ${minimumTotal(triangle)}`)

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
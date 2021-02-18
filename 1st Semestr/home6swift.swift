import Foundation

func miniMaxSum(arr: [Int]) -> Void {
    var min = arr[0]
    var max = arr[0]
    var minIndex: Int
    var maxIndex: Int
    var minSum = 0
    var maxSum = 0
    
    var mutatedArray = arr
    mutatedArray.sort()

    for i in 1..<mutatedArray.count {
        if arr[i] < min {
            minIndex = i
        } else if arr[i] > max {
            maxIndex = i
        }
    }

    for i in 0..<(mutatedArray.count - 1) {
        minSum += mutatedArray[i]
    }

    for i in 1..<mutatedArray.count {
        maxSum += mutatedArray[i]
    } 
    
    print("\(minSum) \(maxSum)")
}
var array = [1, 2, 3, 4, 5]

miniMaxSum(arr: array)
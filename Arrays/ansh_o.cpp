import org.apache.spark.{SparkConf, SparkContext}

object CompareMergeSort {
  
  def main(args: Array[String]): Unit = {
    val input = Array(9, 2, 7, 1, 5, 6, 8, 3, 4)

    def mergeSort(arr: Array[Int]): Array[Int] = {
      if (arr.length <= 1) {
        arr
      } else {
        val mid = arr.length / 2
        val (left, right) = arr.splitAt(mid)
        val leftSorted = mergeSort(left)
        val rightSorted = mergeSort(right)
        merge(leftSorted, rightSorted)
      }
    }
  
    def merge(left: Array[Int], right: Array[Int]): Array[Int] = {
      var result = Array[Int]()
      var i = 0
      var j = 0
      while (i < left.length && j < right.length) {
        if (left(i) <= right(j)) {
          result = result :+ left(i)
          i += 1
        } else {
          result = result :+ right(j)
          j += 1
        }
      }
      result ++= left.slice(i, left.length)
      result ++= right.slice(j, right.length)
      result
    }
  
    // Create Spark context
    val conf = new SparkConf().setAppName("CompareMergeSort")
    val sc = new SparkContext(conf)
    
    // Serial Merge Sort
    val startTimeSerial = System.nanoTime()
    val sortedOutputSerial = mergeSort(input)
    val endTimeSerial = System.nanoTime()
    val runtimeSerialMs = (endTimeSerial - startTimeSerial) / 1000000
    println("Serial Sorted Output: " + sortedOutputSerial.mkString(", "))
    println("Serial Runtime: " + runtimeSerialMs + " ms")
    
    // Parallel Merge Sort
    val startTimeParallel = System.nanoTime()
    val inputRDD = sc.parallelize(input)
    val sortedOutputParallel = mergeSort(inputRDD.collect())
    val endTimeParallel = System.nanoTime()
    val runtimeParallelMs = (endTimeParallel - startTimeParallel) / 1000000
    println("Parallel Sorted Output: " + sortedOutputParallel.mkString(", "))
    println("Parallel Runtime: " + runtimeParallelMs + " ms")
    
    // Stop Spark context
    sc.stop()
  }
}

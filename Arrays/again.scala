import scala.util.Random
//val numNodes = 100
//val conf = new SparkConf().setAppName("CompareMergeSort").setMaster(s"local[$numNodes]")
val conf = new SparkConf().setAppName("CompareMergeSort")
val sc = new SparkContext(conf)

object CompareMergeSort {

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
  
  def main(args: Array[String]): Unit = {
    val n = 50000
    val input = Array.fill(n)(Random.nextInt(n))
    // val input = Array(9, 2, 7, 1, 5, 6, 8, 3, 4)
    
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
    // val inputRDD = sc.parallelize(input).repartition(10)
    val sortedOutputParallel = mergeSort(inputRDD.collect())
    val endTimeParallel = System.nanoTime()
    val runtimeParallelMs = (endTimeParallel - startTimeParallel) / 1000000
    println("Parallel Sorted Output: " + sortedOutputParallel.mkString(", "))
    println("Parallel Runtime: " + runtimeParallelMs + " ms")
  }
}

CompareMergeSort.main(Array())

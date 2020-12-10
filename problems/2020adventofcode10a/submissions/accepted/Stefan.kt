import java.util.*

fun main(args: Array<String>) {
  val s = Scanner(System.`in`)
  val adapters = mutableListOf(0)
  while (s.hasNext()) {
    adapters.add(s.nextInt())
  }
  adapters.add(adapters.max()!! + 3)
  adapters.sort()

  val diffs = arrayOf(0, 0, 0, 0)
  for(i in 0 until adapters.size - 1) {
    diffs[adapters[i+1] - adapters[i]]++
  }

  println(diffs[1] * diffs[3])
}

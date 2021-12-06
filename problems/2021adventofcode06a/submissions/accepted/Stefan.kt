import java.util.*

fun main() {
  val s = Scanner(System.`in`).useDelimiter("""[,\s]""")
  val timers = MutableList(9) {0}
  while (s.hasNext()) {
    timers[s.nextInt()]++
  }
  repeat(80) {
    timers.add(0)
    val zero = timers.removeFirst()
    timers[6] += zero
    timers[8] += zero
  }
  println(timers.sum())
}

import java.util.*

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`).useDelimiter("""\sx=|\.\.|,y=|,z=|\n""")
  val status = mutableMapOf<Triple<Int, Int, Int>, Boolean>()
  while (s.hasNext()) {
    val newStatus = s.next() == "on"
    val xMin = s.nextInt().coerceAtLeast(-50)
    val xMax = s.nextInt().coerceAtMost(50)
    val yMin = s.nextInt().coerceAtLeast(-50)
    val yMax = s.nextInt().coerceAtMost(50)
    val zMin = s.nextInt().coerceAtLeast(-50)
    val zMax = s.nextInt().coerceAtMost(50)
    for (x in xMin..xMax) {
      for (y in yMin..yMax) {
        for (z in zMin..zMax) {
          status[Triple(x, y, z)] = newStatus
        }
      }
    }
  }

  println(status.count { it.value })
}

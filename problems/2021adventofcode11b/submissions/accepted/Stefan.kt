import java.util.*

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`)
  val energy = mutableMapOf<Pair<Int, Int>, Int>()
  var i = 0
  while (s.hasNext()) {
    s.next().map { it.toString().toInt() }.forEachIndexed { j, level -> energy[Pair(i, j)] = level }
    i++
  }
  for(step in 1..Int.MAX_VALUE) {
    var flashes = 0
    val increases = ArrayDeque<Pair<Int, Int>>()
    increases.addAll(energy.keys)
    while (increases.isNotEmpty()) {
      val p = increases.removeFirst()
      if(p !in energy.keys) {
        continue
      }
      energy[p] = energy[p]!! + 1
      if (energy[p] == 10) {
        flashes++
        for (x in -1..1) {
          for (y in -1..1) {
            increases.addLast(Pair(p.first + x, p.second + y))
          }
        }
      }
    }
    if(flashes == energy.size) {
      println(step)
      return
    }
    for ((p, level) in energy) {
      if (level > 9) {
        energy[p] = 0
      }
    }
  }
}

import java.util.*

data class Coord(val x: Int, val y: Int) {
  operator fun plus(p: Pair<Int, Int>): Coord = Coord(x + p.first, y + p.second)
}

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`)
  val map = buildMap<Coord, Int> {
    var i = 0
    while (s.hasNext()) {
      s.next().map { it.toString().toInt() }.forEachIndexed { j, value -> put(Coord(i, j), value) }
      i++
    }
  }

  val start = Coord(0, 0)
  val dist = mutableMapOf<Coord, Int>()
  dist[start] = 0
  val pq = PriorityQueue<Coord>(Comparator.comparingInt { dist.getOrDefault(it, Int.MAX_VALUE) })
  pq.add(start)

  while (pq.isNotEmpty()) {
    val current = pq.remove()
    for (offset in setOf(Pair(-1, 0), Pair(1, 0), Pair(0, -1), Pair(0, 1))) {
      val next = current + offset
      if (next in map.keys) {
        val nextDist = dist[current]!! + map[next]!!
        if (dist.getOrDefault(next, Int.MAX_VALUE) > nextDist) {
          dist[next] = nextDist
          pq.add(next)
        }
      }
    }
  }

  println(dist[Coord(map.keys.maxOf { it.x }, map.keys.maxOf { it.y })])
}
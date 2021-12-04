import java.util.*

data class Point(val x: Int, val y: Int) {
  companion object {
    fun from(pair: Pair<Int, Int>): Point = Point(pair.first, pair.second)
  }
}

data class Line(val start: Point, val end: Point) {
  val points: List<Point>
    get() = when {
      start.x < end.x && start.y < end.y -> (start.x..end.x).zip(start.y..end.y).map { Point.from(it) }
      start.x < end.x && start.y == end.y -> (start.x..end.x).map { Point(it, start.y) }
      start.x < end.x && start.y > end.y -> (start.x..end.x).zip(start.y downTo end.y).map { Point.from(it) }
      start.x == end.x && start.y < end.y -> (start.y..end.y).map { Point(start.x, it) }
      start.x == end.x && start.y > end.y -> (start.y downTo end.y).map { Point(start.x, it) }
      start.x > end.x && start.y < end.y -> (start.x downTo end.x).zip(start.y..end.y).map { Point.from(it) }
      start.x > end.x && start.y == end.y -> (start.x downTo end.x).map { Point(it, start.y) }
      start.x > end.x && start.y > end.y -> (start.x downTo end.x).zip(start.y downTo end.y).map { Point.from(it) }
      else -> throw IllegalStateException()
    }
}

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`).useDelimiter("""\n|\s->\s|,""")
  val lines = buildList {
    while (s.hasNext()) {
      add(Line(Point(s.nextInt(), s.nextInt()), Point(s.nextInt(), s.nextInt())))
    }
  }

  println(lines.flatMap { it.points }.groupBy { it }.count { it.value.size > 1 })
}

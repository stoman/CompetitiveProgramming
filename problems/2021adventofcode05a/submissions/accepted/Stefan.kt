import java.util.*

data class Point(val x: Int, val y: Int)

data class Line(val start: Point, val end: Point) {
  val points: List<Point>
    get() = when {
      start.x == end.x -> (start.y.coerceAtMost(end.y)..end.y.coerceAtLeast(start.y)).map { Point(start.x, it) }
      start.y == end.y -> (start.x.coerceAtMost(end.x)..end.x.coerceAtLeast(start.x)).map { Point(it, start.y) }
      else -> listOf()
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

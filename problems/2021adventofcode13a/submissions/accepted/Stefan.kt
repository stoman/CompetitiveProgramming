import java.util.*

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`).useDelimiter("\n\n")
  var dots = buildSet {
    val sDots = Scanner(s.next()).useDelimiter("""[,\n]""")
    while (sDots.hasNext()) {
      add(Pair(sDots.nextInt(), sDots.nextInt()))
    }
  }
  val sFolds = Scanner(s.next()).useDelimiter("""\s*fold along\s*|=""")
  while (sFolds.hasNext()) {
    val horizontal = sFolds.next() == "x"
    val foldLine = sFolds.nextInt()
    dots = if (horizontal) {
      dots.map { Pair(if (it.first < foldLine) it.first else (2 * foldLine - it.first), it.second) }.toSet()
    } else {
      dots.map { Pair(it.first, if (it.second < foldLine) it.second else (2 * foldLine - it.second)) }.toSet()
    }
    println(dots.size)
    // Return after one fold.
    return
  }
}

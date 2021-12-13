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
  val sFolds = Scanner(s.next()).useDelimiter("""\s*fold along\s*|=|\s""")
  while (sFolds.hasNext()) {
    val horizontal = sFolds.next() == "x"
    val foldLine = sFolds.nextInt()
    dots = if (horizontal) {
      dots.map { Pair(if (it.first < foldLine) it.first else (2 * foldLine - it.first), it.second) }.toSet()
    } else {
      dots.map { Pair(it.first, if (it.second < foldLine) it.second else (2 * foldLine - it.second)) }.toSet()
    }
  }
  for(y in 0..dots.maxOf { it.second }) {
    for(x in 0..dots.maxOf { it.first }) {
      print(if(Pair(x, y) in dots) '#' else '.')
    }
    println()
  }
}

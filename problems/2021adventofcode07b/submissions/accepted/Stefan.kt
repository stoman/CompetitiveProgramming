import java.util.*
import kotlin.math.absoluteValue

private fun cost(positions: List<Int>, alignment: Int): Int = positions.map { (alignment - it).absoluteValue }.map { it * (it+1)/2 }.sum()

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`).useDelimiter("""[,\s]""")
  val positions = buildList {
    while (s.hasNext()) {
      add(s.nextInt())
    }
  }
  println((positions.minOrNull()!!..positions.maxOrNull()!!).map { cost(positions, it) }.minOrNull())
}

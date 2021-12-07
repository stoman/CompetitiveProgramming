import java.util.*
import kotlin.math.absoluteValue

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`).useDelimiter("""[,\s]""")
  val positions = buildList {
    while (s.hasNext()) {
      add(s.nextInt())
    }
  }
  val median = positions.sorted()[positions.size/2]
  println(positions.map { (median - it).absoluteValue }.sum())
}

import java.util.*
import kotlin.math.absoluteValue

fun main() {
  val s = Scanner(System.`in`).useDelimiter("""=|\.\.|,|\s|\n""")
  s.next() // target
  s.next() // area:
  s.next() // x=
  s.nextInt() // xMin
  s.nextInt() // xMax
  s.next() // ,
  s.next() // y=
  val yMin = s.nextInt()
  val yMax = s.nextInt()

  var ret = -1
  for (i in 0..yMin.absoluteValue + 1) {
    var sim = 0
    var yVelocity = i
    var maxHeight = sim
    while (sim >= yMin) {
      if (sim <= yMax) {
        ret = ret.coerceAtLeast(maxHeight)
      }
      sim += yVelocity
      maxHeight = maxHeight.coerceAtLeast(sim)
      yVelocity--
    }
  }
  println(ret)
}

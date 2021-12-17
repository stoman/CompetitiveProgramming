import java.util.*
import kotlin.math.absoluteValue
import kotlin.math.sign

fun simulate(xMin: Int, xMax: Int, yMin: Int, yMax: Int, x: Int, y: Int): Boolean {
  var xVelocity = x
  var yVelocity = y
  var xPos = 0
  var yPos = 0
  while (xPos <= xMax && yPos >= yMin) {
    if (xPos in xMin..xMax && yPos in yMin..yMax) {
      return true
    }
    xPos += xVelocity
    yPos += yVelocity
    xVelocity -= xVelocity.sign
    yVelocity--
  }
  return false
}

fun main() {
  val s = Scanner(System.`in`).useDelimiter("""=|\.\.|,|\s|\n""")
  s.next() // target
  s.next() // area:
  s.next() // x=
  val xMin = s.nextInt()
  val xMax = s.nextInt()
  s.next() // ,
  s.next() // y=
  val yMin = s.nextInt()
  val yMax = s.nextInt()

  var count = 0
  for (x in 1..xMax) {
    for (y in yMin..yMin.absoluteValue) {
      if(simulate(xMin, xMax, yMin, yMax, x, y)) {
        count++
      }
    }
  }
  println(count)
}

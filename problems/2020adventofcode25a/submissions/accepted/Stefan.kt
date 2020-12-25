import java.math.BigInteger
import java.util.*

const val mod = 20201227

fun main(args: Array<String>) {
  val s = Scanner(System.`in`)
  val cardPublicKey = s.nextInt()
  val doorPublicKey = s.nextInt()

  var cardLoopSize : Long? = null
  var doorLoopSize : Long? = null
  var t = 1
  var i = 0L
  while(cardLoopSize == null || doorLoopSize == null) {
    if(cardLoopSize == null && t == cardPublicKey) {
      cardLoopSize = i
    }
    if(doorLoopSize == null && t == doorPublicKey) {
      doorLoopSize = i
    }
    i++
    t = (t*7) % mod
  }

  var r = 1
  repeat(((cardLoopSize * doorLoopSize) % (mod-1)).toInt()) {
    r = (r*7) % mod
  }
  println(r)
}

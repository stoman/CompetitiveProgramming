import java.math.BigInteger
import java.util.*

data class EuclidReturn(val g: BigInteger, val y: BigInteger, val x: BigInteger)

fun euclid(a: BigInteger, b: BigInteger): EuclidReturn {
  if (a == BigInteger.ZERO) {
    return EuclidReturn(b, BigInteger.ZERO, BigInteger.ONE)
  }
  val (g, y, x) = euclid(b % a, a)
  return EuclidReturn(g, x - (b / a) * y, y)
}

fun modInv(a: BigInteger, m: BigInteger): BigInteger {
  val (_, y, _) = euclid(a, m)
  return (y + m) % m
}

fun main() {
  val s = Scanner(System.`in`).useDelimiter("\\s|,")
  s.nextInt()
  val a = mutableListOf<BigInteger>()
  val n = mutableListOf<BigInteger>()
  var i = BigInteger.ZERO
  while (s.hasNext()) {
    val bus = s.next()
    if (bus != "x") {
      val ni = bus.toBigInteger()
      a.add((ni - i) % ni)
      n.add(ni)
    }
    i++
  }
  val p = n.reduce(BigInteger::times)
  val y = n.map { p / it }
  val z = y.indices.map { modInv(y[it], n[it]) }
  println(y.indices.map { a[it] * y[it] * z[it] }.reduce(BigInteger::plus) % p)
}

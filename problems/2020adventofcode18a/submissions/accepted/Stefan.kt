import java.math.BigInteger
import java.util.*

fun evaluate(it: Iterator<Char>): BigInteger {
  var buffer = BigInteger.ZERO
  var operation = '?'
  while(it.hasNext()) {
    when (val next = it.next()) {
      ')' -> return buffer
      in setOf('*', '+') -> operation = next
      ' ' -> { }
      else -> {
        val term: BigInteger = if(next == '(') evaluate(it) else next.toString().toBigInteger()
        when(operation) {
          '?' -> buffer = term
          '*' -> buffer *= term
          '+' -> buffer += term
        }
      }
    }
  }
  return buffer
}

fun main() {
  val s = Scanner(System.`in`).useDelimiter("\n")

  var r = BigInteger.ZERO
  while(s.hasNext()) {
    r += evaluate(s.next().iterator())
  }
  println(r)
}

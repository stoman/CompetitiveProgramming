import java.math.BigInteger
import java.util.*

fun evaluate(it: Stack<Char>, start: BigInteger = BigInteger.ZERO, readClosingBracket: Boolean = false): BigInteger {
  var buffer = start
  var operation = '?'
  while(it.isNotEmpty()) {
    when (val next = it.pop()) {
      ')' -> {
        if(!readClosingBracket) {
          it.add(next)
        }
        return buffer
      }
      in setOf('*', '+') -> operation = next
      ' ' -> { }
      else -> {
        val term: BigInteger = if(next == '(') evaluate(it, readClosingBracket = true) else next.toString().toBigInteger()
        when(operation) {
          '?' -> buffer = term
          '*' -> buffer *= evaluate(it, start = term)
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
    val stack = Stack<Char>()
    stack.addAll(s.next().toList().reversed())
    r += evaluate(stack)
  }
  println(r)
}

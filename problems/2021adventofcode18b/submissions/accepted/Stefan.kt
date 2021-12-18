import java.util.*

abstract class SnailfishNumber(var parent: SnailfishPair?) {
  abstract fun encodingLength(): Int
  abstract fun magnitude(): Long
  abstract fun copy(): SnailfishNumber
  abstract fun addToLeftmostValue(summand: Long)
  abstract fun addToRightmostValue(summand: Long)
  abstract fun explode(depth: Int = 0): Boolean
  abstract fun split(): Boolean

  fun reduce() {
    do {
      var didSomething = explode()
      if (!didSomething) {
        didSomething = split()
      }
    } while (didSomething)
  }

  operator fun plus(other: SnailfishNumber): SnailfishNumber {
    require(parent == null && other.parent == null)
    val sum = SnailfishPair(null, copy(), other.copy())
    sum.left.parent = sum
    sum.right.parent = sum
    sum.reduce()
    return sum
  }

  companion object {
    fun read(input: String): SnailfishNumber {
      if (input[0] != '[') {
        return SnailfishLiteral(null, input[0].digitToInt().toLong())
      }

      val left = read(input.drop(1))
      require(input[1 + left.encodingLength()] == ',')
      val right = read(input.drop(2 + left.encodingLength()))
      require(input[2 + left.encodingLength() + right.encodingLength()] == ']')
      val pair = SnailfishPair(null, left, right)
      left.parent = pair
      right.parent = pair
      return pair
    }
  }
}

class SnailfishPair(parent: SnailfishPair?, var left: SnailfishNumber, var right: SnailfishNumber) :
  SnailfishNumber(parent) {
  override fun encodingLength(): Int = 3 + left.encodingLength() + right.encodingLength()

  override fun magnitude(): Long = 3 * left.magnitude() + 2 * right.magnitude()

  override fun copy(): SnailfishNumber {
    val c = SnailfishPair(parent, left.copy(), right.copy())
    c.left.parent = c
    c.right.parent = c
    return c
  }

  override fun addToLeftmostValue(summand: Long) {
    left.addToLeftmostValue(summand)
  }

  override fun addToRightmostValue(summand: Long) {
    right.addToRightmostValue(summand)
  }

  private fun addToUpwardsThenLeftmostValue(summand: Long) {
    val parentNonNull = parent ?: return
    if (parentNonNull.right == this) {
      parentNonNull.addToUpwardsThenLeftmostValue(summand)
    } else
      parentNonNull.right.addToLeftmostValue(summand)
  }

  private fun addToUpwardsThenRightmostValue(summand: Long) {
    val parentNonNull = parent ?: return
    if (parentNonNull.left == this) {
      parentNonNull.addToUpwardsThenRightmostValue(summand)
    } else
      parentNonNull.left.addToRightmostValue(summand)
  }

  override fun toString(): String = "[$left,$right]"

  override fun explode(depth: Int): Boolean {
    if (depth >= 3) {
      if (left is SnailfishPair) {
        val leftAsSnailfishPair = left as SnailfishPair
        require(leftAsSnailfishPair.left is SnailfishLiteral && leftAsSnailfishPair.right is SnailfishLiteral)
        addToUpwardsThenRightmostValue((leftAsSnailfishPair.left as SnailfishLiteral).value)
        right.addToLeftmostValue((leftAsSnailfishPair.right as SnailfishLiteral).value)
        left = SnailfishLiteral(this, 0)
        return true
      }

      if (right is SnailfishPair) {
        val rightAsSnailfishPair = right as SnailfishPair
        require(rightAsSnailfishPair.left is SnailfishLiteral && rightAsSnailfishPair.right is SnailfishLiteral)
        left.addToRightmostValue((rightAsSnailfishPair.left as SnailfishLiteral).value)
        addToUpwardsThenLeftmostValue((rightAsSnailfishPair.right as SnailfishLiteral).value)
        right = SnailfishLiteral(this, 0)
        return true
      }
    }

    if (left.explode(depth + 1)) {
      return true
    }
    return right.explode(depth + 1)
  }

  override fun split(): Boolean {
    if (left is SnailfishLiteral) {
      val leftAsSnailfishLiteral = left as SnailfishLiteral
      if (leftAsSnailfishLiteral.value >= 10) {
        left = fromValue(this, leftAsSnailfishLiteral.value)
        return true
      }
    }

    if (left.split()) {
      return true
    }

    if (right is SnailfishLiteral) {
      val rightAsSnailfishLiteral = right as SnailfishLiteral
      if (rightAsSnailfishLiteral.value >= 10) {
        right = fromValue(this, rightAsSnailfishLiteral.value)
        return true
      }
    }

    return right.split()
  }

  companion object {
    fun fromValue(parent: SnailfishPair, value: Long): SnailfishPair {
      val ret = SnailfishPair(parent, SnailfishLiteral(null, value / 2), SnailfishLiteral(null, (value + 1) / 2))
      ret.left.parent = ret
      ret.right.parent = ret
      return ret
    }
  }
}

class SnailfishLiteral(parent: SnailfishPair?, var value: Long) : SnailfishNumber(parent) {
  override fun encodingLength(): Int = 1

  override fun magnitude(): Long = value

  override fun copy(): SnailfishNumber = SnailfishLiteral(parent, value)

  override fun addToLeftmostValue(summand: Long) {
    value += summand
  }

  override fun addToRightmostValue(summand: Long) {
    value += summand
  }

  override fun toString(): String = value.toString()

  override fun explode(depth: Int): Boolean = false

  override fun split(): Boolean = false
}

@ExperimentalStdlibApi
fun main() {
  val s = Scanner(System.`in`)
  val numbers = buildList {
    while (s.hasNext()) {
      add(SnailfishNumber.read(s.next()))
    }
  }
  var max = -1L
  for (a in numbers) {
    for (b in numbers) {
      if (a != b) {
        val magnitude = (a + b).magnitude()
        max = max.coerceAtLeast(magnitude)
      }
    }
  }
  println(max)
}

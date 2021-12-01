import java.util.*
import kotlin.collections.ArrayDeque
import kotlin.properties.ReadOnlyProperty
import kotlin.reflect.KProperty

/** Provides an [ArrayDeque] that is capped to a maximum size while reading. */
class CapacityConstrainedDeque<T>(private val maxSize: Int) : ReadOnlyProperty<Nothing?, ArrayDeque<T>> {
  private var deque: ArrayDeque<T> = ArrayDeque(maxSize)

  override fun getValue(thisRef: Nothing?, property: KProperty<*>): ArrayDeque<T> {
    while (deque.size > maxSize) {
      deque.removeFirst()
    }
    return deque
  }
}

fun main() {
  val s = Scanner(System.`in`)
  val compareDistance = 3

  val history: ArrayDeque<Int> by CapacityConstrainedDeque(compareDistance + 1)
  var increases = 0
  while (s.hasNext()) {
    history.add(s.nextInt())
    if (history.size == compareDistance + 1 && history.last() > history.first()) {
      increases++
    }
  }

  println(increases)
}

import java.util.*

private operator fun Int.times(map: MutableMap<String, Int>): MutableMap<String, Int> {
  val r = mutableMapOf<String, Int>()
  for (key in map.keys) {
    r[key] = this * map[key]!!
  }
  return r
}

fun main(args: Array<String>) {
  val s = Scanner(System.`in`)

  val contents = mutableMapOf<String, MutableMap<String, Int>>()
  while (s.hasNext()) {
    val color = s.next() + ' ' + s.next()
    contents[color] = mutableMapOf()
    s.next() // bags
    s.next() // contain
    do {
      try {
        val count = s.nextInt()
        val childColor = s.next() + ' ' + s.next()
        contents[color]!![childColor] = count
      } catch (e: InputMismatchException) {
        s.next() // no
        s.next() // other
        s.next() // bags.
        break
      }
    } while (s.next().endsWith(','))
  }

  val expandedContents = mutableMapOf<String, MutableMap<String, Int>>()
  fun expandColor(color: String) {
    if (expandedContents.containsKey(color)) {
      return
    }

    expandedContents[color] = mutableMapOf()
    for (childColor in contents[color]!!.keys) {
      expandColor(childColor)
      if (expandedContents[childColor]!!.isEmpty() || childColor == "shiny gold") {
        expandedContents[color]!![childColor] = contents[color]!![childColor]!!
      } else {
        expandedContents[color]?.plusAssign(contents[color]!![childColor]!! * expandedContents[childColor]!!)
      }
    }
  }
  for (color in contents.keys) {
    expandColor(color)
  }

  println(expandedContents.values.count { "shiny gold" in it.keys })
}

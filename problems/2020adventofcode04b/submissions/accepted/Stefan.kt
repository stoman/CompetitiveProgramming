import java.util.*

fun isValid(category: String, value: String): Boolean {
  return try {
    when (category) {
      "byr" -> value.toInt() in 1920..2002
      "iyr" -> value.toInt() in 2010..2020
      "eyr" -> value.toInt() in 2020..2030
      "hgt" -> when {
        value.endsWith("cm") -> value.dropLast(2).toInt() in 150..193
        value.endsWith("in") -> value.dropLast(2).toInt() in 59..76
        else -> false
      }
      "hcl" -> value.matches(Regex("#[0-9a-f]{6}"))
      "ecl" -> value in setOf("amb", "blu", "brn", "gry", "grn", "hzl", "oth")
      "pid" -> value.matches(Regex("\\d{9}"))
      else -> false
    }
  } catch (e: NumberFormatException) {
    false
  }
}

fun main(args: Array<String>) {
  val s = Scanner(System.`in`).useDelimiter("\n\n")
  val requiredFields = setOf("byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid")

  var r = 0
  while (s.hasNext()) {
    val ss = Scanner(s.next()).useDelimiter("\\s|:")
    val providedFields = mutableSetOf<String>()
    while (ss.hasNext()) {
      val category = ss.next()
      val value = ss.next()
      if (isValid(category, value)) {
        providedFields.add(category)
      }
    }
    if (providedFields.containsAll(requiredFields)) {
      r++
    }
  }
  println(r)
}

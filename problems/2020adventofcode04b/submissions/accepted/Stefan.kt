import java.util.*

fun isValid(category: String, value: String): Boolean {
  return try {
    when (category) {
      "byr" -> (1920 until 2003).contains(value.toInt())
      "iyr" -> (2010 until 2021).contains(value.toInt())
      "eyr" -> (2020 until 2031).contains(value.toInt())
      "hgt" -> when {
        value.endsWith("cm") -> (150 until 194).contains(value.dropLast(2).toInt())
        value.endsWith("in") -> (59 until 77).contains(value.dropLast(2).toInt())
        else -> false
      }
      "hcl" -> value.matches(Regex("#[0-9a-f]{6}"))
      "ecl" -> setOf("amb", "blu", "brn", "gry", "grn", "hzl", "oth").contains(value)
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

import java.util.*

fun main() {
  val s = Scanner(System.`in`).useDelimiter("\n\n")
  val requiredFields = setOf("byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid")

  var r = 0
  while (s.hasNext()) {
    val ss = Scanner(s.next()).useDelimiter("\\s|:")
    val providedFields = mutableSetOf<String>()
    while(ss.hasNext()) {
      providedFields.add(ss.next())
      ss.next()
    }
    if(providedFields.containsAll(requiredFields)) {
      r++
    }
  }
  println(r)
}

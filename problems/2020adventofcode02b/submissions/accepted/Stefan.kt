import java.util.Scanner

fun main(args: Array<String>) {
    val s = Scanner(System.`in`).useDelimiter("-|\\s|:\\s")

    var r = 0
    while(s.hasNext()) {
        val a = s.nextInt() - 1
        val b = s.nextInt() - 1
        val char = s.next()[0]
        val password = s.next()
        if((password[a] == char) xor (password[b] == char)) {
            r++
        }
    }
    println(r)
}

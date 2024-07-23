fun main () {
    var inputData = getInput()
    calculate(inputData)
}

fun getInput() : ArrayList<Int>{
    //kotlin Collection API인 map 함수는 각 원소를 원하는 형태로 변환하는 기능(람다 함수형 프로그래밍)
    var (n,m) = readLine()!!.split(' ').map { it.toInt() }
    return arrayListOf<Int>(n, m)
}

fun calculate(data : ArrayList<Int>) {
    var a : Int = 100 - data[0]
    var b : Int = 100 - data[1]
    var c : Int = 100 - (a+b)
    var d : Int = (a*b)
    var q : Int = d / 100
    var r : Int = d % 100
    printResult("${a} ${b} ${c} ${d} ${q} ${r}\n${c+q} ${r}")
}

fun printResult(text: String){
    println(text)
}
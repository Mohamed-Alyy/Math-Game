
#include <iostream>
#include <random>

// دالة لاختيار عشوائي لإحدى العمليات الرياضية (+, -, *, /)
char getRandomOperator() {
    // إعداد محرك عشوائي
    std::random_device rd;
    std::mt19937 gen(rd());

    // تعيين نطاق العمليات الرياضية الممكنة
    std::uniform_int_distribution<> dis(0, 3);

    // مصفوفة تحتوي على العمليات الرياضية الممكنة
    char operators[] = {'+', '-', '*', '/'};

    // توليد رقم عشوائي وإرجاعه
    return operators[dis(gen)];
}

int main() {
    // اختبار الدالة
    for (int i = 0; i < 10; ++i) {
        std::cout  << getRandomOperator() << std::endl;
    }
 //   std::cout << 5 + 6 << std::endl;

    return 0;
}

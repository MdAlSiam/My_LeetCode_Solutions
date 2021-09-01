class Solution {
    complex<int> parse(string str) {
        int i = str.find('+');
        int real = stoi(str.substr(0, i));
        int imaginary = stoi(str.substr(i+1, str.length()-i-2));
        complex<int> res(real, imaginary);
        return res;
    }
public:
    string complexNumberMultiply(string num1, string num2) {
        complex<int> n1 = parse(num1);
        complex<int> n2 = parse(num2);

        complex<int> product = n1*n2;

        return to_string(real(product))+"+"+to_string(imag(product))+"i";
    }
};
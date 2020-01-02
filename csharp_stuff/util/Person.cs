using System;
using System.Text.RegularExpressions;

public class Person {

    private string _firstname;
    private string _secondname;
    private string _fullname;
    private int _age;
    private PythonBuiltins python = new PythonBuiltins();

    public Person() {
        _firstname = _secondname = _fullname = "";
        _age = 0;
    }
    
    public Person(string fname, string sname, int age) {
        fname = fname.Trim();
        sname = sname.Trim();
        if (!ValidNames(fname, sname) || !ValidAge(age)) {
            throw new ArgumentException("Invalid parameters for instantiation");
        }
        _firstname = fname;
        _secondname = sname;
        _fullname = _firstname + " " + _secondname;
        _age = age;
    }

    public bool ValidNames(string fname, string sname) {
        if (fname == null || sname == null) {
            return false;
        }
        if (fname == "" || sname == "") {
            return false;
        }
        string full = fname + " " + sname;
        if (!Regex.IsMatch(full, @"^([a-zA-Z]+\s[a-zA-Z]+)$")) {
            return false;
        }
        return true;
    }

    public bool ValidAge(int age) {
        return !(age < 0);
    }

    public string GetName() {
        return _fullname;
    }

    public int GetAge() {
        return _age;
    }

    public override string ToString() {
        string result = String.Format("<Name: {0}>\n<Age: {1}>", _fullname, _age);
        return result;
    }
}
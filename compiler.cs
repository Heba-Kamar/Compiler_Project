using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

public class Token
{
    public string Type { get; set; }
    public string Value { get; set; }

    public Token(string type, string value)
    {
        Type = type;
        Value = value;
    }

    public override string ToString()
    {
        return $"<Type = {Type}, Value = {Value}>";
    }
}

public class Lexer
{
    private static readonly List<(string Type, string Pattern)> tokendef = new List<(string, string)>
    {
        ("Keyword", @"\b(int|float|if|else|while|return|for|do|break|continue|void|char|double|short|long|unsigned|signed|const|static|struct|union|enum|typedef|sizeof|volatile|register|extern|goto|switch|case|default|main|printf|auto)\b"),
        ("Identifier", @"\b[a-zA-Z_][a-zA-Z0-9_]*\b"),
        ("Numeric_constant", @"\b\d+(\.\d+)?\b"),
        ("String", "\".*?\""),
        ("Char", "'.'"),
        ("Operator", @"[+\-*/%=&|<>!^~]+"),
        ("Special_character", @"[{}()\[\],;]"),
        ("Comment", @"(//.?$|/\.?\/)"),
        ("New_line", @"\n"),
        ("White_space", @"\s+")
    };

    public static List<Token> Tokenize(string input)
    {
        var tokens = new List<Token>();
        foreach (var (type, pattern) in tokendef)
        {
            var matches = Regex.Matches(input, pattern, RegexOptions.Multiline);
            foreach (Match match in matches)
            {
                tokens.Add(new Token(type, match.Value));
            }
        }
        return tokens;
    }
}

public class Program
{
    public static void Main()
    {
        Console.WriteLine("Enter your C code (end with an empty line):");
        string code = "";
        string line;
        while ((line = Console.ReadLine() ?? "") != null && line != "")
        {
            code += line + "\n";
        }

        var tokens = Lexer.Tokenize(code);
        foreach (var token in tokens)
        {
                Console.WriteLine(token);
        }
    }
}

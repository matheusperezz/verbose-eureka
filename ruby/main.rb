=begin

    $               A global var
    @               An instance variable
    [a-z] or _      A local variable
    [A-Z]           A constante
    @@              A class variable
=end

def saySomething()
    puts "Seila mano, oi talvez?"
end

def calcSquare(height, weight)
    puts height*weight
end

MYCONSTANT = "Testing"
$x = 10

# puts (1..10).to_a
# print ('a'..'z').to_a

# range between 8 to 20
numbers = (1..20).to_a
print numbers.reject { |subrange| subrange < 8 }

# All squares between 1 and 20
numbers.each { |num| print "#{num*num} " }

# verifying if this element is on a range
(1..20) === 15 # true
(8..15) === 2  # false

# print defined? $x --> Print the scope of an variable

# When case
score = 70
result = case score
    when 0..40 
        "Fail"
    when 41..60 
        "Pass"
    when 61..70 
        "Pass with Merit"
    when 71..100 
        "Pass with Distinction"
    else 
        "Invalid Score"
end

puts result
puts "Testando alguma coisa"

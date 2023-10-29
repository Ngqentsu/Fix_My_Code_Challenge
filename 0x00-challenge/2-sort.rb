###
#
#  Sort integer arguments (ascending) 
#
###

result = []
ARGV.each do |arg|
    # skip if not an integer
    next if arg !~ /^-?\d+$/

    # convert to integer
    i_arg = arg.to_i

    # Find the correct position to insert the integer
    i = 0
    while i < result.size && result[i] < i_arg do
        i += 1
    end

    # Insert the integer at the correct position
    result.insert(i, i_arg)
end

puts result

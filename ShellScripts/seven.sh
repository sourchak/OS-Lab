read -p "Enter three numbers: " -a nums

( [[ ${nums[0]} -ge ${nums[1]} ]] && [[ ${nums[0]} -ge ${nums[2]} ]] && echo "The largest is: ${nums[0]}" ) \
    || ( [[ ${nums[1]} -ge ${nums[0]} ]] && [[ ${nums[1]} -ge ${nums[2]} ]] && echo "The largest is: ${nums[1]}" ) \
    || ( [[ ${nums[2]} -ge ${nums[0]} ]] && [[ ${nums[2]} -ge ${nums[1]} ]] && echo "The largest is: ${nums[2]}" )

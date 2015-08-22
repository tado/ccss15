in_thread do
  loop do
    i = 0
    11.times do
      play ([64, 66, 71, 73, 74, 66, 64, 71, 66, 74, 73][i]), release: 0.2, pan: -0.8
      sleep 0.15
      i = i + 1
    end
  end
end

loop do
  i = 0
  11.times do
    play ([64, 66, 71, 73, 74, 66, 64, 71, 66, 74, 73][i]), release: 0.2, pan: 0.8
    sleep 0.151
    i = i + 1
  end
end
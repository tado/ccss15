in_thread do
  loop do
    i = 0
    11.times do
      play ([64, 66, 71, 73, 74, 66, 64, 71, 66, 74, 73][i]), release: 0.2, pan: 1
      sleep 0.15
      i = i + 1
    end
  end
end

in_thread do
  loop do
    i = 0
    11.times do
      play ([64, 66, 71, 73, 74, 66, 64, 71, 66, 74, 73][i]), release: 0.2, pan: -0.25
      sleep 0.151
      i = i + 1
    end
  end
end

in_thread do
  loop do
    i = 0
    11.times do
      play ([64, 66, 71, 73, 74, 66, 64, 71, 66, 74, 73][i]) + 12, release: 0.2, pan: 0.25
      sleep 0.152
      i = i + 1
    end
  end
end

in_thread do
  loop do
    i = 0
    11.times do
      play ([64, 66, 71, 73, 74, 66, 64, 71, 66, 74, 73][i]) + 12, release: 0.2, pan: -1
      sleep 0.153
      i = i + 1
    end
  end
end
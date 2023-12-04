#!/bin/bash

# 执行 pod lib lint
pod lib lint MentaVlionSDK.podspec --allow-warnings --skip-import-validation --use-libraries --verbose --no-clean

# 检查 pod lib lint 是否成功
if [ $? -eq 0 ]; then
  # 如果 pod lib lint 成功，则执行 pod trunk push
  pod trunk push MentaVlionSDK.podspec --allow-warnings --verbose --skip-import-validation
else
  # 如果 pod lib lint 失败，则输出错误消息
  echo "pod lib lint 失败，无法执行 pod trunk push。"
fi

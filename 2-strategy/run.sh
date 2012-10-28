#!/bin/bash
case "$1" in
        bfs)
            ant runbfs
            ;;

        dfs)
            ant rundfs
            ;;

        *)
            echo $"Usage: $0 {bfs|dfs}"
            exit 1
esac
